func groupAnagrams(strs []string) [][]string {
	groups := [][]string{}

	for _, str := range strs {
		matchingGroupFound := false
		for i, group := range groups {
			if isAnagram(str, group[0]) {
				matchingGroupFound = true
				group = append(group, str)
				groups[i] = group
			}	
		}
		if !matchingGroupFound {
			newGroup := []string{str}
			groups = append(groups, newGroup)
		}
	}

	return groups
}

func isAnagram(
	a string,
	b string,
) bool {
	aFrequency := getRuneFrequency(a)
	bFrequency := getRuneFrequency(b)
	return equalRuneFrequency(aFrequency, bFrequency) && equalRuneFrequency(bFrequency, aFrequency)
}

func getRuneFrequency(
	s string,
) map[rune]int {
	frequency := map[rune]int{}
	for _, c := range s {
		frequency[c]++
	}
	return frequency
}

func equalRuneFrequency(
	a map[rune]int,
	b map[rune]int,
) bool {
	for c, _ := range a {
		if a[c] != b[c] {
			return false
		}
	}
	return true
}