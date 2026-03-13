import time
import threading
import sysconfig
from concurrent.futures import ThreadPoolExecutor
from concurrent.futures import ProcessPoolExecutor

def very_long_task():
    x = 1
    for i in range(10**7):
        x *= i
    return x

def test_sequential(tests: int = 4):
    for _ in range(tests):
        very_long_task()

def test_threading(tests: int = 4):
    futures = []
    with ThreadPoolExecutor(max_workers=tests) as pool:
        for i in range(tests):
            futures.append(pool.submit(very_long_task))
    for f in futures:
        f.result()

def test_multiprocessing(tests: int = 4):
    futures = []
    with ProcessPoolExecutor(max_workers=tests) as pool:
        for i in range(tests):
            futures.append(pool.submit(very_long_task))
    for f in futures:
        f.result()

if __name__ == "__main__":
    print(f"Is free-threaded: {sysconfig.get_config_var("Py_GIL_DISABLED")}")

    start = time.perf_counter()
    test_sequential()
    print(f"Sequential {int((time.perf_counter() - start) * 1000)}")

    start = time.perf_counter()
    test_threading()
    print(f"Threading {int((time.perf_counter() - start) * 1000)}")

    start = time.perf_counter()
    test_multiprocessing()
    print(f"Multiprocessing {int((time.perf_counter() - start) * 1000)}")