movies = LOAD '/deep/3/movies.item' USING PigStorage('|')
	AS (movieID:int, movieTitle:chararray, releaseDate:chararray, videoRelease:chararray, imdblink:chararray);
ratings = LOAD '/deep/3/ratings.data' AS (userID:int, movieID:int, rating:int, ratingTime:int);

nameLookup = FOREACH movies GENERATE movieID, movieTitle;
ratingsByMovie = GROUP ratings BY movieID;
avgRatings = FOREACH ratingsByMovie GENERATE group as movieID, AVG(ratings.rating) as avgRating;

fiveStarMovies = FILTER avgRatings BY avgRating == 5.0;
fiveStarsWithData = JOIN fiveStarMovies BY movieID, nameLookup BY movieID;

STORE fiveStarsWithData INTO '/deep/out';
