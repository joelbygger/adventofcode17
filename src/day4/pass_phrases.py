import collections


# def _read_file():
#    for row in open("input"):
#        yield row

def only_unique(words):
    # A Set, with counter for duplicated words.
    counts = collections.Counter(words)
    # A list of tuples with most common words (I only ask for the most common one).
    # The tuple is like a dict, key : value. 
    # From list get first (only) elem and access the value.
    return counts.most_common(1)[0][1] <= 1


def count_valid_readable_code(file, anagram):
    i = 0
    for row in open(file):
        words = row.split()
        if anagram:
            words = [''.join(sorted(word)) for word in words]
        if only_unique(words):
            i += 1

    return i


def count_valid_list_comprehension(file):
    return sum([1 for row in open(file) if only_unique(row.split())])


def main(file):
    print("Duplicated passwords readable: ", count_valid_readable_code(file, anagram=False))
    print("Duplicated passwords list comprehension: ", count_valid_list_comprehension(file))

    print("Duplicated passwords readable: ", count_valid_readable_code(file, anagram=True))


if __name__ == "__main__":
    main("input")
