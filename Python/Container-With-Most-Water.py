#!/usr/bin/env python


def maxArea(self, height):
    num = len(height)
    left = 0
    right = num - 1
    Area = (num - 1) * min(height[left], height[right])
    while left <= right:
        while left <= right and height[left] <= height[right]:
            left += 1
            Area = max(Area, (right - left + 1) * min(height[left], height[right]))
        while left < right and height[left] > height[right]:
            right -= 1
            Area = max(Area, (right - left + 1) * min(height[left], height[right]))
    Area = max(Area, (right - left) * min(height[left], height[right]))
    return Area