func twoSum(nums []int, target int) []int {
	res := []int{}

	seen := map[int]int{}
	for j, num := range nums {
		complement := target - num
		if i, exists := seen[complement]; exists {
			res = append(res, i, j)
		}
		seen[num] = j
	}
	
	return res
}
