type Solution struct{}

func (s *Solution) Encode(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    strs = encodeEmpty(strs)
    return strings.Join(strs, "\\,")
}

func encodeEmpty(strs []string) []string {
    res := []string{}
    for _, s := range strs {
        if s == "" {
            res = append(res, "\\e")
        } else {
            res = append(res, s)
        }
    }
    return res
}

func (s *Solution) Decode(encoded string) []string {
    if encoded == "" {
        return []string{}
    }
    if !strings.Contains(encoded, "\\,") {
        return decodeEmpty([]string{encoded})
    }
    split := strings.Split(encoded, "\\,")
    return decodeEmpty(split)
}

func decodeEmpty(strs []string) []string {
    res := []string{}
    for _, s := range strs {
        if s == "\\e" {
            res = append(res, "")
        } else {
            res = append(res, s)
        }
    }
    return res
}
