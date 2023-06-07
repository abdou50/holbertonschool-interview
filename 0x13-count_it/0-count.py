#!/usr/bin/python3
""" function"""
import requests


def count_words(subreddit, word_list, after='', wordcount={}):
    """ function """

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'custom'}
    payload = {'limit': '100', 'after': after}
    response = requests.get(url, headers=headers,
                            params=payload, allow_redirects=False)

    if not response.status_code == 200:
        return
    data = response.json().get('data')
    after = data.get('after')
    children_list = data.get('children')

    for child in children_list:
        title = child.get('data').get('title')
        for word in word_list:
            ocurrences = title.lower().split().count(word.lower())
            if ocurrences > 0:
                if word in wordcount:
                    wordcount[word] += ocurrences
                else:
                    wordcount[word] = ocurrences

    if after is not None:
        return count_words(subreddit, word_list, after, wordcount)
    else:
        if not len(wordcount) > 0:
            return
        iterator = sorted(wordcount.items(),
                          key=lambda kv: (-kv[1], kv[0]))
        for key, value in iterator:
            print('{}: {}'.format(key.lower(), value))
