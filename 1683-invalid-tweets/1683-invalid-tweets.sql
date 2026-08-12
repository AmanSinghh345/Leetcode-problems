# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets
WHERE char_LENGTH(content)>15;