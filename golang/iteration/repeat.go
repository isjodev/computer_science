package iteration

func Repeat(character string, repetitions int) string {
	var repeated string
	if repetitions == 0 {
		repetitions = 5
	}

	for i := 0; i < repetitions; i++ {
		repeated = repeated + character
	}
	return repeated
}
