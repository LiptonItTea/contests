"""
Comprehensive comparison: Sequential vs Free-threading vs Multiprocessing

This benchmark compares parallel computation approaches with SHARED DATA:
1. Sequential: Single-threaded baseline
2. Free-threading: Multiple threads with no GIL, accessing shared memory
3. Multiprocessing: Multiple separate processes, data must be serialized/copied

Key differences:
- Free-threading: Shared memory access (efficient, no copying)
- Multiprocessing: Data must be copied to each process (serialization overhead)

This demonstrates the PRIMARY advantage of free-threading!
"""

import os
import sys
import time
from concurrent.futures import ThreadPoolExecutor, ProcessPoolExecutor
from multiprocessing import cpu_count


def cpu_bound_task_with_data(data: list, start_idx: int, end_idx: int, should_return=False) -> list:
    """
    CPU-intensive task that processes and MODIFIES data in-place.

    For threading: Modifies data directly in memory (no need to return)
    For multiprocessing: Must return the modified slice (serialization overhead!)
    """
    for i in range(start_idx, end_idx):
        value = data[i]
        # CPU-intensive computation
        computed = 0
        for j in range(100):
            computed += (value * j) % 997

        # Modify data in-place
        data[i] = computed % 1000

    if should_return:
        return data[start_idx:end_idx]
    else:
        return None


def benchmark_sequential(shared_data: list, num_workers: int, data_size: int) -> float:
    """Run tasks sequentially (baseline) - processes entire dataset."""
    chunk_size = data_size // num_workers
    start = time.perf_counter()
    for i in range(num_workers):
        start_idx = i * chunk_size
        end_idx = start_idx + chunk_size if i < num_workers - 1 else data_size
        cpu_bound_task_with_data(shared_data, start_idx, end_idx, False)
    end = time.perf_counter()
    return end - start


def benchmark_threaded(shared_data: list, num_workers: int, data_size: int) -> float:
    """
    Threading: Passes shared_data by reference (no copying).
    All threads access the same memory.
    """
    chunk_size = data_size // num_workers
    start = time.perf_counter()
    with ThreadPoolExecutor(max_workers=num_workers) as executor:
        futures = []
        for i in range(num_workers):
            start_idx = i * chunk_size
            end_idx = start_idx + chunk_size if i < num_workers - 1 else data_size
            # shared_data passed as reference - no copying!
            futures.append(executor.submit(cpu_bound_task_with_data, shared_data, start_idx, end_idx, False))
        results = [f.result() for f in futures]
    end = time.perf_counter()
    return end - start


def benchmark_multiprocessing(shared_data: list, num_workers: int, data_size: int) -> float:
    """
    Multiprocessing: shared_data must be pickled and copied to each process.
    Results must be returned (serialization overhead).
    """
    chunk_size = data_size // num_workers
    start = time.perf_counter()
    with ProcessPoolExecutor(max_workers=num_workers) as executor:
        futures = []
        for i in range(num_workers):
            start_idx = i * chunk_size
            end_idx = start_idx + chunk_size if i < num_workers - 1 else data_size
            # shared_data must be serialized/copied to each process!
            # Results must be returned (more serialization!)
            futures.append(executor.submit(cpu_bound_task_with_data, shared_data, start_idx, end_idx, True))

        # Collect all returned chunks (extends the overhead)
        results = []
        for f in futures:
            chunk = f.result()
            if chunk is not None:
                results.extend(chunk)
    end = time.perf_counter()
    return end - start


def main():
    # Configuration
    num_workers = min(10, cpu_count())
    data_size = 10_000_0  # 10M elements in shared data (~268 MB)

    print("=" * 80)
    print("Performance Comparison: Threading vs Multiprocessing with Shared Data")
    print("=" * 80)
    print(f"\nPython version: {sys.version}")

    # Check if GIL is enabled
    if not getattr(sys, '_is_gil_enabled', lambda: True)():
        print(f"Mode: Free-threaded (no GIL)")
    else:
        print("Mode: GIL-based (traditional)")

    # Initialize shared data
    print(f"\nInitializing shared data ({data_size:,} elements)...")

    data_size_mb = (data_size * 28) / (1024 * 1024)  # Approx size in MB
    print(f"Shared data initialized (~{data_size_mb:.1f} MB)")

    print(f"\nConfiguration:")
    print(f"  - Number of workers: {num_workers}")
    print(f"  - Shared data size: {data_size:,} elements")
    print(f"  - CPU cores: {cpu_count()}")
    print(f"\nKey difference:")
    print(f"  - Threading: Data shared by reference (no copying)")
    print(f"  - Multiprocessing: Data serialized & copied to each process")

    print("\n" + "-" * 80)
    print("Running benchmarks...")
    print("-" * 80)

    # 1. Sequential baseline
    print(f"\n1. Sequential execution ({num_workers} chunks, one at a time):")
    shared_data = list(range(data_size))
    seq_time = benchmark_sequential(shared_data, num_workers, data_size)
    print(f"   Time: {seq_time:.3f} seconds")

    # 2. Threading
    threading_label = "Threading (no-GIL)" if (hasattr(sys, '_is_gil_enabled') and not sys._is_gil_enabled()) else "Threading (with GIL)"
    print(f"\n2. {threading_label} ({num_workers} threads, shared memory):")
    shared_data = list(range(data_size))
    thread_time = benchmark_threaded(shared_data, num_workers, data_size)
    print(f"   Time: {thread_time:.3f} seconds")
    thread_speedup = seq_time / thread_time
    print(f"   Speedup: {thread_speedup:.2f}x")

    # 3. Multiprocessing
    print(f"\n3. Multiprocessing ({num_workers} processes, data copied):")
    shared_data = list(range(data_size))
    mp_time = benchmark_multiprocessing(shared_data, num_workers, data_size)
    print(f"   Time: {mp_time:.3f} seconds")
    mp_speedup = seq_time / mp_time
    print(f"   Speedup: {mp_speedup:.2f}x")

    # Results Summary
    print("\n" + "=" * 80)
    print("Results Summary:")
    print("=" * 80)

    # Create results table
    print(f"\n{'Approach':<25} {'Time (s)':<15} {'Speedup':<15} {'Efficiency':<15}")
    print("-" * 80)
    print(f"{'Sequential':<25} {seq_time:>10.3f}     {'1.00x':>10}     {'100.0%':>10}")
    print(f"{threading_label:<25} {thread_time:>10.3f}     {thread_speedup:>10.2f}x     {(thread_speedup/num_workers)*100:>10.1f}%")
    print(f"{'Multiprocessing':<25} {mp_time:>10.3f}     {mp_speedup:>10.2f}x     {(mp_speedup/num_workers)*100:>10.1f}%")

    # Winner comparison
    print("\n" + "-" * 80)
    print("Direct comparison: Free-threading vs Multiprocessing")
    print("-" * 80)
    if thread_time < mp_time:
        advantage = (mp_time / thread_time - 1) * 100
        print(f"Free-threading is FASTER by {advantage:.1f}%")
        print(f"  Free-threading: {thread_time:.3f}s")
        print(f"  Multiprocessing: {mp_time:.3f}s")
    elif mp_time < thread_time:
        advantage = (thread_time / mp_time - 1) * 100
        print(f"Multiprocessing is FASTER by {advantage:.1f}%")
        print(f"  Multiprocessing: {mp_time:.3f}s")
        print(f"  Free-threading: {thread_time:.3f}s")
    else:
        print("Both approaches have similar performance")

    print("=" * 80)


if __name__ == "__main__":
    main()