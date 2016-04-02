function showMatches( image1, image2, t )
%SHOWMATCHES Summary of this function goes here
%   Detailed explanation goes here

if size(image1, 3) > 1
    image1 = rgb2gray(image1);
end

if size(image2, 3) > 1
    image2 = rgb2gray(image2);
end
h = waitbar(0, 'Initializing...');
if t == 1
    pointsImage1  = detectHarrisFeatures(image1);
    pointsImage2 = detectHarrisFeatures(image2);
elseif t == 2
    pointsImage1  = detectSURFFeatures(image1);
    pointsImage2 = detectSURFFeatures(image2);

elseif t == 3
    pointsImage1  = detectFASTFeatures(image1);
    pointsImage2 = detectFASTFeatures(image2);
end
waitbar(.4, h, 'Features detected...');
[featuresImage1,   validPointsImage1]  = extractFeatures(image1,  pointsImage1);
[featuresImage2, validPointsImage2]  = extractFeatures(image2, pointsImage2);
waitbar(.6, h, 'Features extracted...');
indexPairs = matchFeatures(featuresImage1, featuresImage2);
waitbar(1, h, 'Features matched...');
matchedImage1  = validPointsImage1(indexPairs(:, 1));
matchedImage2 = validPointsImage2(indexPairs(:, 2));
close(h);
figure;
showMatchedFeatures(image1, image2, matchedImage1, matchedImage2, 'montage');
end

