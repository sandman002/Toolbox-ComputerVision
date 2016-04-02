function image = sharpen( image, radius, amount, threshold )


if nargin < 2
    radius = 1;
    amount = 0.8;
    threshold = 0;
elseif nargin < 3
    amount = 0.8;
    threshold = 0;
elseif nargin < 4
    threshold = 0;
end

image = imsharpen(image, 'Radius', radius, 'Amount', amount, 'Threshold', threshold);

end
