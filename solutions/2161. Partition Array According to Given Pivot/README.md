# [2161. Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/)
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

- Every element less than pivot appears before every element greater than pivot.
- Every element equal to pivot appears in between the elements less than and greater than pivot.
- The relative order of the elements less than pivot and the elements greater than pivot is maintained.
    - More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.

Return nums after the rearrangement.

### Constraints:
- `1 <= nums.length <= 10^5`
- `-10^6 <= nums[i] <= 10^6`
- `pivot` equals to an element of `nums`.
---

# Алгоритм решения:
## Вариант 1:
1. Создаем вектор по размеру исходного и заполняем его значением pivot. Берем указатели на начало и конец списка.
2. Проходимся циклом по каждому значению и вставляем значение по нужному указателю в зависимости от положения относительно pivot. Двигаем указатель.
3. В конце переворачиваем часть списка, которая больше pivot, так как в условии относительные порядок должен сохраниться. В нашем случае вставка происходила с конца, поэтому все элементы бы реверсированы.

Сложность: О(N)
Память: О(N)

## Вариант 2:
Можно воспользоваться функцией stable_partition (или реализовать ее самостоятельно). В таком случае удастся уменьшить затраты памяти до О(1)
