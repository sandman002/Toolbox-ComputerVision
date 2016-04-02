function [fLMedS, inliers, matchedImage1, matchedImage2] = computeFundamentalMatrix(image1, image2)


if size(image1, 3) > 1
    image1 = rgb2gray(image1);
end

if size(image2, 3) > 1
    image2 = rgb2gray(image2);
end
pointsImage1  = detectSURFFeatures(image1);
pointsImage2 = detectSURFFeatures(image2);
h = waitbar(0,'SURF features detected ...');
[featuresImage1,   validPointsImage1]  = extractFeatures(image1,  pointsImage1);
[featuresImage2, validPointsImage2]  = extractFeatures(image2, pointsImage2);
waitbar(0.3 , h, 'SURF features extracted ...');
indexPairs = matchFeatures(featuresImage1, featuresImage2);
waitbar(.6,h,'features matched ...');
matchedImage1  = validPointsImage1(indexPairs(:, 1));
matchedImage2 = validPointsImage2(indexPairs(:, 2));
waitbar(0.7,h,'Matches in image extracted ...');
[fLMedS, inliers] = estimateFundamentalMatrix(matchedImage1, matchedImage2);%, 'NumTrials', 4000);
waitbar(1,h,'Fundamental Matrix calculated ...');
close(h);

