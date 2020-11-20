import pass_phrases


def test_examples_task_1():
    e1 = "aa bb cc dd ee"
    e2 = "aa bb cc dd aa"
    e3 = "aa bb cc dd aaa"
    assert pass_phrases.only_unique(e1.split()) is True
    assert pass_phrases.only_unique(e2.split()) is False
    assert pass_phrases.only_unique(e3.split()) is True


def test_task_1():
    assert 383 == pass_phrases.count_valid_readable_code("input", False)
    assert 383 == pass_phrases.count_valid_list_comprehension("input")


def test_examples_task_2():
    assert 3 == pass_phrases.count_valid_readable_code("input_examples_task2", True)


def test_task_2():
    assert 265 == pass_phrases.count_valid_readable_code("input", True)
