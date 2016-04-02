function getContours( image, contourLvl )

if nargin < 2
    contourLvl = 1;
end

if size(image, 3) > 1
    image = rgb2gray(image);
end

imcontour(image, contourLvl);
end

