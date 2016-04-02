%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Author : Sandeep Manandhar
% University of Burgundym France
% MSCV6
% Radon Transform
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% inputs:
% image
% minimum value for angle
% maximum value for angle
% toggle guides and axis
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function[] = radonLine(imageOriginal, angleMin, angleMax, guide)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% initial processing - grayscale and sobel

if size(imageOriginal,3) ~=1
imageOriginal = rgb2gray(imageOriginal);
end
image = edge(imageOriginal,'sobel');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Radon transform for given angle range
theta = angleMin:angleMax;
[R,xp] = radon(image,theta);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% maximum
maxR = max(R(:));
[xIndex theta] = find(R(:,:) == maxR);
rho = (xp(xIndex(1)));
tht = theta*pi/180;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% intercept of the radius at detected line
rhoX = (rho)*(cos(tht));
rhoY = rho*sin(tht);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[r c] = size(image);
maxLength = sqrt(r^2 + c^2);
o = floor((size(image) + 1)/2); %CENTER OF THE IMAGE 

px = rhoX + o(2); %rhox wrt to central axis so add offset to reach there
py = -rhoY + o(1); %rhoY wrt to central axis so flip it with -1 and add offset

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Arrangements for the line to be drawn
X = linspace(px-maxLength, px+maxLength);
Y = -(tan(tht+pi/2+0.000000001)*X + abs(rho)/sin(tht+0.0000000001)) + o(1) ;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

figure(1);
imshow(imageOriginal);
hold on;
line(X'+o(2), Y', 'LineWidth', 2, 'Color', [0,1,0]); %% line found

if guide == 1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Draw axis and guides
plot(px, py, '*r');
line([0 + o(2); px ], [0 + o(1); py], 'LineWidth', 2, 'Color', [0,0,1]);
line([o(2); o(2)], [0; 2*o(2)], 'LineWidth', 2, 'Color', [1, 0,0]);
line( [0; 2*o(2)],[o(1); o(1)], 'LineWidth', 2, 'Color', [1, 0,0]);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
end
end