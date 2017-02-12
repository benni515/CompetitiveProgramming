from sum_with_bounds import *

cool_ass_list = [1, -2, 3, 4 -5, 10, -3, 1, -1, 2, -1, 8, -100]


(left, right), maxsum = max_value_subarray(cool_ass_list)

print("Left bound: {}\nRight bound: {}".format(left, right))
print("-- Original list --")
print(cool_ass_list)

print("\n-- Optimal list --")
print(cool_ass_list[left:right])
print("\n-- Maximum value --")
print(maxsum)
