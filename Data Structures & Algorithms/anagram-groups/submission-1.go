func groupAnagrams(strs []string) [][]string {
	groups := map[string][]string{}
	for _, str := range strs {
		sortedStr := sortString(str)
		if _, exists := groups[sortedStr]; exists {
			groups[sortedStr] = append(groups[sortedStr], str)
		} else {
			groups[sortedStr] = []string{str}
		}
	}

	res := [][]string{}
	for _, group := range groups {
		res = append(res, group)
	}
	return res
}

func isAnagram(
	a string,
	b string,
) bool {
	return sortString(a) == sortString(b)
}

func sortString(
	a string,
) string {
	split := strings.Split(a, "")
	sort.Strings(split)
	return strings.Join(split, "")
}