#!/usr/bin/python3
'''
    Gathers todo
'''
if __name__ == "__main__":
    import json, requests

    todo = requests.get(
        'https://jsonplaceholder.typicode.com/todos')

    user = requests.get(
        'https://jsonplaceholder.typicode.com/users')

    todo = todo.json()
    user = user.json()

    new_dict = {}

    for x in user:
        new_dict[x['id']] = []
        for c in todo:
            if x['id'] == c['userId']:
                new_dict[x['id']].append(
                    {"username": x['name'], "task": c['title'],
                     "completed": c['completed']})

    filename = 'todo_all_employees.json'
    with open(filename, mode='w+', encoding='utf-8') as a_file:
        json.dump(new_dict, a_file)
