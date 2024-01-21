import csv
import sys

from util import Node, StackFrontier, QueueFrontier

import pandas as pd

total = None

def load_data(directory):
    """
    Load data from CSV files into memory.
    """
    stars = pd.read_csv(f"{directory}/stars.csv")
    people = pd.read_csv(f"{directory}/people.csv")
    movies = pd.read_csv(f"{directory}/movies.csv")
    movies.rename(columns={"id": "movie_id"}, inplace=True)
    people.rename(columns={"id": "person_id"}, inplace=True)

    global total
    total = stars.merge(movies, on="movie_id", how="left").merge(people, on="person_id", how="left")
    total = total.drop(["birth"], axis=1)
    total = total.sort_index(axis=1)
    print(total)


def main():
    if len(sys.argv) > 2:
        sys.exit("Usage: python degrees.py [directory]")
    directory = sys.argv[1] if len(sys.argv) == 2 else "small"

    print("Loading data...")
    load_data(directory)
    print("Data loaded.")

    source = person_id_for_name(input("Name: "))
    if source is None:
        sys.exit("Person not found.")
    target = person_id_for_name(input("Name: "))
    if target is None:
        sys.exit("Person not found.")

    shortest_path(source, target)


def shortest_path(source, target):
    """
    Returns the shortest list of (movie_id, person_id) pairs
    that connect the source to the target.

    If no possible path, returns None.
    """

    explored = []
    queue = [[source]]
     
    if source == target:
        df = total.loc[total["person_id"] == source]
        series =  df[["movie_id", "person_id"]].iloc[0,:]

        print(series.iloc[0].item(), series.iloc[1].item())
        return

    while queue:
        path = queue.pop(0)
        node = path[-1]
         
        if node not in explored:
            neighbours = total.loc[node]
             
            for neighbour in neighbours:
                new_path = list(path)
                new_path.append(neighbour)
                queue.append(new_path)

                if neighbour == target:
                    return new_path
            explored.append(node)


def person_id_for_name(name):
    """
    Returns the IMDB id for a person's name,
    resolving ambiguities as needed.
    """
    global total
    id = total[["name", "person_id"]].loc[total["name"] == name]["person_id"].iloc[0].item()
    return id


def neighbors_for_person(person_id):
    """
    Returns (movie_id, person_id) pairs for people
    who starred with a given person.
    """
    movie_ids = people[person_id]["movies"]
    neighbors = set()
    for movie_id in movie_ids:
        for person_id in movies[movie_id]["stars"]:
            neighbors.add((movie_id, person_id))
    return neighbors


if __name__ == "__main__":
    main()
