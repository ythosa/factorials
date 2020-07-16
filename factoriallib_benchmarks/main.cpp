#include "benchmark/benchmark.h"
#include "falgo.h"

static void BM_PrimeSwing(benchmark::State& state) {
    // Perform setup here
    for (auto _ : state) {
        // This code gets timed
        falgo::PrimeSwing::Count(20);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_PrimeSwing);
// Run the benchmark
BENCHMARK_MAIN();
