import (
	"cmp"
	"slices"
)

func topKFrequent(nums []int, k int) []int {
	frequencies := getNumberFrequencies(nums)

	// Sort the nums, by the frequency we found
	numbers := getUniqueNumbers(nums)
	slices.SortFunc(numbers, func(a int, b int) int {
		return cmp.Compare(frequencies[b], frequencies[a])
	})
	return numbers[:k]
}

func getUniqueNumbers(
	nums []int,
) []int {
	res := []int{}

	seen := map[int]bool{}
	for _, num := range nums {
		if _, ok := seen[num]; ok {
			continue
		}
		seen[num] = true
		res = append(res, num)
	}
	
	return res
}

func getNumberFrequencies(
	nums []int,
) map[int]int {
	res := map[int]int{}
	for _, num := range nums {
		res[num]++
	}
	return res
}
