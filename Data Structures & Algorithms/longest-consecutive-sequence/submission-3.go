import "slices"

func longestConsecutive(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return 1
	}

	nums = getSorted(getUnique(nums))

	prev := nums[0]
	currentSequenceLength := 1
	longestSequenceLength := 1
	for _, num := range nums[1:] {
		if num == (prev + 1) {
			currentSequenceLength++
		} else {
			if currentSequenceLength > longestSequenceLength {
				longestSequenceLength = currentSequenceLength
			}
			currentSequenceLength = 1
		}
		prev = num
	}

	if currentSequenceLength > longestSequenceLength {
		longestSequenceLength = currentSequenceLength
	}
	return longestSequenceLength
}

func getSorted(nums []int) []int {
	slices.Sort(nums)
	return nums
}

func getUnique(nums []int) []int {
	res := []int{}
	seen := map[int]bool{}
	for _, num := range nums {
		if _, ok := seen[num]; !ok {
			res = append(res, num)
		}
		seen[num] = true
	}
	return res
}
