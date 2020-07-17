<br>

<h1 align="center">Factorials</h1>
<div align="center">

[![Badge](https://img.shields.io/badge/Open-Source-important.svg?style=flat-square&logo=open-source-initiative&logoWidth=15&logoColor=orange)](https://ru.wikipedia.org/wiki/Open_source)
[![Badge](https://img.shields.io/badge/Made_with-Affection-ff69b4.svg?style=flat-square&logo=ko-fi&logoWidth=15&logoColor=ff69b4)](https://i.pinimg.com/736x/d7/5f/e3/d75fe32e7af10c3ed0bafb98816a6ce2.jpg)
    
</div>

<br>

## Description
This repository was created in order to conduct research on the topic 
"comparison and selection of the most effective factorial algorithm". 
The algorithms are compared by using the [google/benchmark](https://github.com/google/benchmark) library. 
There are also tests for each algorithm that use the [google/googletest](https://github.com/google/googletest) library. 
* Tests you can find [here](https://github.com/Ythosa/factorials/tree/master/factoriallib_tests);
* Benchmarks you can find [here](https://github.com/Ythosa/factorials/tree/master/factoriallib_benchmarks);
* Factorials library itself [here](https://github.com/Ythosa/factorials/tree/master/factoriallib).

## Results
<div align="center">
<img src="https://github.com/Ythosa/factorials/blob/master/assets/results.jpg" alt="Results" />
</div>

As a result, more effective algorithm was
[FactNaive](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L280).
However, the most efficient algorithm is one that simply returns values from an array: 
[TakingFromArray](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L147) 
(even if it initializes it: [InitAndTakeFromArray](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L158)).

Other algorithms:
* [SimpleFactNaive](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L302),
* [SimpleWhile](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L124),
* [SimpleRecursion](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L115),
* [Tree](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L175),
* [FactFast](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L252),
* [FactFactor](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L203),
* [Prime Swing](https://github.com/Ythosa/factorials/blob/54a93c3b326b5143bd223258fb385f78ad79ba75/factoriallib/falgo.cpp#L91).

## Links
*	What is factorial: https://en.wikipedia.org/wiki/Factorial

## FAQ
*Q*: How can I help to develop this project?  
*A*: You can put a :star: :3

<br>

<div align="center">
  Copyright 2020 Ythosa
</div>
