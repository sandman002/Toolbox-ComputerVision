function  image  = ApplyMorph( image, method, structuringElement, param1, param2 )

% Method = 'dilate' 'erode' 'open' 'close'
% Structuring Elements
% se1 = strel('square',11)      % 11-by-11 square
% se2 = strel('line', 10, 45)     % length 10, angle 45 degrees
% se3 = strel('disk', 15)        % disk, radius 15
% se4 = strel('ball', 15, 5)      % ball, radius 15, height 5



if strcmp(structuringElement, 'square') || strcmp(structuringElement, 'disk')
    se = strel(structuringElement, param1);
elseif strcmp(structuringElement, 'line') || strcmp(structuringElement, 'ball')
    se = strel(structuringElement, param1, param2);
else
    error('Wrong structuring element type.');
end


%
if strcmp(method, 'dilate')
    image = imdilate(image, se);
elseif strcmp(method, 'erode')
    image = imerode(image, se);
elseif strcmp(method, 'open')
    image = imopen(image, se);
elseif strcmp(method, 'close')
    image = imclose(image, se);

end


end