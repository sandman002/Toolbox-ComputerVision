%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  Sandeep Manandhar
%% University of Burgundy, France
%% MSCV6
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% inputs
% image
% kernelSize
% deprecating value C; C = mean - threhold
%% output
% threhold image
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function ThresholdImage = localThresh(image, kernelSize, tunableValue)
if(size(image, 2) ~=1)
image = rgb2gray(image);
end
image = im2double(image);
[r c] = size(image);
kernelRadius = (kernelSize -1)/2;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%padding the image
impadded = padarray(image, [kernelRadius kernelRadius], 'replicate');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%making the integral image
intImg = cumsum((cumsum(impadded'))');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%preparing the mean image from integral image
p = intImg(1+kernelRadius: r+kernelRadius, 1+kernelRadius: c+ kernelRadius) + ... %from padded start to end
    intImg(1: r, 1: c) - ...
    intImg(1: r, 1+kernelRadius: c+ kernelRadius) - ...
    intImg(1+kernelRadius: r+kernelRadius, 1: c);

meanImage = p/(kernelRadius^2);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%threshold here
someImage = meanImage - image - tunableValue/255;
ThresholdImage = someImage < 0 ;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

end


