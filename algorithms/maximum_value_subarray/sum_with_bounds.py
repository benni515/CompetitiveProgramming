def max_value_subarray(l):
    #NOTE: This function returns the indices in terms of list splicing,
    # ex: if left is 0 and right is 2, then the max sum is the indices
    # 0 and 1, NOT 0, 1 and 2. The right bound is exclusive, not inclusive

    n = len(l)
    j = 0

    left = 0
    right = 0

    optimal = -2**32
    local_sum = 0

    for i in range(n):
        local_sum += l[i]
        if local_sum > optimal:
            # The best sum + current location is greater than the best sum
            # Therefore the best sum is now (best_sum + local_sum)
            optimal = local_sum
            left = j
            right = i + 1
        if local_sum < 0:
            # Since the local sum is less than 0, it will never be better
            # The best sum cannot possibly contain this element, so the j
            # variable is set to the element to the right of this one, and
            # the local sum is reset
            j = i + 1
            local_sum = 0

        # And that's it, that's all you need.

    return (left, right), optimal

