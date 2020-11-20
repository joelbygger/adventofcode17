import pass_phrases


def test_examples_task_1():
    r1 = "aa bb cc dd ee"
    r2 = "aa bb cc dd aa"
    r3 = "aa bb cc dd aaa"
    assert pass_phrases.only_unique(r1.split()) is True
    assert pass_phrases.only_unique(r2.split()) is False
    assert pass_phrases.only_unique(r3.split()) is True


def test_task_1():
    assert 383 == pass_phrases.count_valid_readable("input")
    assert 383 == pass_phrases.count_valid_list_comprehension("input")
