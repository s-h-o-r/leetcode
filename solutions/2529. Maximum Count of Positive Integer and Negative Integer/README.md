# [2529. Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/)

Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in `nums` is `pos` and the number of negative integers is `neg`, then return the maximum of `pos` and `neg`.
Note that 0 is neither positive nor negative.

### Constraints:
- `1 <= nums.length <= 2000`
- `-2000 <= nums[i] <= 2000`
- `nums` is sorted in a non-decreasing order.
---

## Алгоритм решения:

Воспользуемся алгоритмом поиска элемента, который равен или больше заданного (lower_bound). Этот алгоритм представлен в стандартной библиотеке stl, но мы реализуем его [самостоятельно](#реализация-lower_bound).
Для отрицательных чисел мы ищем 0 или большее значение. Для позитивных 1. С помощью нашего алгоритма получаем итератор на нужные элементы. Для отрицательных чисел это будет конец массива. Для положительных начало. Можем получить рассторяние с помощью distance. Для отрицательных `[nums.begin(), lower_bound.res)`. для положительных `[lower_bound.res, nums.end())` . Теперь возвращаем максимальное значение от полученных результатов.


### Реализация lower_bound
1. Ищем середину подмассива, сравниваем со значением.
2. Если мы попали в значение меньше, то все, что находится левее, нам не нужно, сдвигаем итератор +1 от проверяемого значения (проверяемое значение мы тоже уже знаем, оно меньше). Продолжаем поиск уже в новом подмассиве.
3. Если значение больше, то все, что находится справа,  нам не нужно. Просто меняем размер массива, итератор остается на месте.
4. Выходим из цикла, когда размер массива стал равным 0. Теперь begin у нас указывает на элемент, которые больше или равен искомому.

---
Сложность: О(logN)
Память: О(1)

