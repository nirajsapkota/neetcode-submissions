func isAnagram(s string, t string) bool {
	sRuneFrequency := getRuneFrequency(s)
	tRuneFrequency := getRuneFrequency(t)

	sInT := frequencyOfEachRuneMatches(sRuneFrequency, tRuneFrequency)
	tInS := frequencyOfEachRuneMatches(tRuneFrequency, sRuneFrequency)
	if sInT && tInS {
		return true
	}

	return false
}

func getRuneFrequency(
	s string,
) map[rune]int {
	result := map[rune]int{}
	for _, c := range s {
		result[c]++
	}
	return result
}

func frequencyOfEachRuneMatches(
	a map[rune]int,
	b map[rune]int,
) bool {
	for char, _ := range a {
		if a[char] != b[char] {
			return false
		}
	}
	return true
} 