func productExceptSelf(nums []int) []int {
    output := make([]int, len(nums))
    for i, _ := range output {
        output[i] = 1
    }

    for i, num := range nums {
        for j, _ := range output {
            if i == j {
                continue
            }
            output[j] *= num
        }
    }

    return output
}
