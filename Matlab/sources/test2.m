function varargout = test2(varargin)
% TEST2 MATLAB code for test2.fig
%      TEST2, by itself, creates a new TEST2 or raises the existing
%      singleton*.
%
%      H = TEST2 returns the handle to a new TEST2 or the handle to
%      the existing singleton*.
%
%      TEST2('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TEST2.M with the given input arguments.
%
%      TEST2('Property','Value',...) creates a new TEST2 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before test2_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to test2_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help test2

% Last Modified by GUIDE v2.5 23-Apr-2015 22:01:49

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @test2_OpeningFcn, ...
    'gui_OutputFcn',  @test2_OutputFcn, ...
    'gui_LayoutFcn',  [] , ...
    'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before test2 is made visible.
function test2_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to test2 (see VARARGIN)
set(handles.axes1,'Visible','off');
set(handles.axes2,'Visible','off');
set(handles.axesHist1,'Visible','off');
set(handles.axesHist2,'Visible','off');
% Choose default command line output for test2
handles.output = hObject;
handles.fileLoaded1 = 0;
handles.fileLoaded2 = 0;
handles.kSize = [5 5];
handles.pad = 'replicate';
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes test2 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = test2_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



% --------------------------------------------------------------------
function File_Callback(hObject, eventdata, handles)
% hObject    handle to File (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function Untitled_2_Callback(hObject, eventdata, handles)
% hObject    handle to Untitled_2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function convertGray_Callback(hObject, eventdata, handles)
% hObject    handle to convertGray (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    Gray = rgb2gray(handles.inIm);
    handles.outIm(:,:,1) = Gray;
    handles.outIm(:,:,2) = Gray;
    handles.outIm(:,:,3) = Gray;
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end

% --------------------------------------------------------------------
function invert_Callback(hObject, eventdata, handles)
% hObject    handle to invert (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    handles.outIm = 255 - handles.inIm;
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end
% --------------------------------------------------------------------
function openImage_Callback(hObject, eventdata, handles)
% hObject    handle to openImage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[fileName, pathName, filterindex] = uigetfile({'*.*'},'Load Image File');

if (fileName==0) % cancel pressed
    return;
end
handles.fullPath = [pathName fileName];
[a, b, ext] = fileparts(fileName);
availableExt = {'.bmp','.jpg','.jpeg','.tiff','.png','.gif'};
FOUND = 0;
for (i=1:length(availableExt))
    if (strcmpi(ext, availableExt{i}))
        FOUND=1;
        break;
    end
end
if (FOUND==0)
    h = msgbox('File type not supported!','Error','error');
    return;
end
image1 = imread(handles.fullPath);
handles.inIm = image1;
handles.outIm = image1;
handles.fileLoaded1 = 1; handles.fileLoaded2 = 0;
axes(handles.axes1); cla; imshow(image1, []);
axes(handles.axes2); cla;
handles = makeHistograms(handles);
set(handles.axes1,'Visible','on');
set(handles.axes2,'Visible','off');
set(handles.axesHist1,'Visible','on');
set(handles.axesHist2,'Visible','off');
guidata(hObject, handles);


% --------------------------------------------------------------------
function saveImage_Callback(hObject, eventdata, handles)
% hObject    handle to saveImage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if (handles.fileLoaded2==1)
    [file,path] = uiputfile('*.jpg','Save the processed Image As');
    imwrite(handles.outIm,[path file],'jpg');
end

function handlesNew = makeHistograms(handles)
handlesNew = handles;
if (handles.fileLoaded1 == 1)
    set(handles.axesHist1, 'Visible', 'on');
    axes(handlesNew.axesHist1);
    cla;
    
    ImageData1 = reshape(handlesNew.inIm(:,:,1), [size(handlesNew.inIm, 1) * size(handlesNew.inIm, 2) 1]);
    ImageData2 = reshape(handlesNew.inIm(:,:,2), [size(handlesNew.inIm, 1) * size(handlesNew.inIm, 2) 1]);
    ImageData3 = reshape(handlesNew.inIm(:,:,3), [size(handlesNew.inIm, 1) * size(handlesNew.inIm, 2) 1]);
    [H1, X1] = hist(ImageData1, 1:5:256);
    [H2, X2] = hist(ImageData2, 1:5:256);
    [H3, X3] = hist(ImageData3, 1:5:256);
    hold on;
    plot(X1, H1, 'r');
    plot(X2, H2, 'g');
    plot(X3, H3, 'b');
    axis([0 255 0 max([H1 H2 H3])]);
end
if (handlesNew.fileLoaded2 == 1)
    set(handles.axesHist2, 'Visible', 'on');
    axes(handlesNew.axesHist2);
    cla;
    ImageData1 = reshape(handlesNew.outIm(:,:,1), [size(handlesNew.outIm, 1) * size(handlesNew.outIm, 2) 1]);
    ImageData2 = reshape(handlesNew.outIm(:,:,2), [size(handlesNew.outIm, 1) * size(handlesNew.outIm, 2) 1]);
    ImageData3 = reshape(handlesNew.outIm(:,:,3), [size(handlesNew.outIm, 1) * size(handlesNew.outIm, 2) 1]);
    [H1, X1] = hist(ImageData1, 1:5:256);
    [H2, X2] = hist(ImageData2, 1:5:256);
    [H3, X3] = hist(ImageData3, 1:5:256);
    hold on;
    plot(X1, H1, 'r');
    plot(X2, H2, 'g');
    plot(X3, H3, 'b');
    axis([0 256 0 max([H1 H2 H3])]);
end


% --------------------------------------------------------------------
function filters_Callback(hObject, eventdata, handles)
% hObject    handle to filters (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function mean_Callback(hObject, eventdata, handles)
% hObject    handle to mean (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.kSize = [15 15];
handles.pad = 'replicate';

if (handles.fileLoaded1==1)
    
    [kSz padT] = chooseAverage();
    handles.kSize = [kSz kSz];
    handles.pad = (padT);
    assignin('base', 'h', handles);
    H = fspecial('average', handles.kSize);
    handles.outIm = imfilter(handles.inIm, H, char(handles.pad));
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end







% --------------------------------------------------------------------
function bightnessContrast_Callback(hObject, eventdata, handles)
% hObject    handle to bightnessContrast (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if(handles.fileLoaded1 == 1)
    param = birghtnessContrastUI();
    brightness = param(1);
    contrast = param(2);
    im = handles.inIm;
    assignin('base', 'in', im);
    
    handles.outIm = im + brightness*255;
    if(handles.outIm) < 0; handles.outIm = 0;
    elseif handles.outIm > 255 handles.outIm = 255;
    end
    factor = (2*(contrast+1)/(2 - contrast))
    handles.outIm =  factor*(handles.outIm);% - 128) + 128;
    if(handles.outIm) < 0; handles.outIm = 0;
    elseif handles.outIm > 255 handles.outIm = 255;
    end
    assignin('base', 'in', handles.outIm);
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function noise_Callback(hObject, eventdata, handles)
% hObject    handle to noise (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function gauss_Callback(hObject, eventdata, handles)
% hObject    handle to gauss (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if(handles.fileLoaded1 == 1)
    param = gaussParam();
    handles.outIm = imnoise(handles.inIm, 'gaussian', param(1), param(2));
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function poisson_Callback(hObject, eventdata, handles)
% hObject    handle to poisson (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if(handles.fileLoaded1 == 1)
    handles.outIm = imnoise(handles.inIm, 'poisson');
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end

% --------------------------------------------------------------------
function saltPepper_Callback(hObject, eventdata, handles)
% hObject    handle to saltPepper (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if(handles.fileLoaded1 == 1)
    param = saltPepDensity();
    handles.outIm = imnoise(handles.inIm, 'salt & pepper', param);
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end

% --------------------------------------------------------------------
function speckle_Callback(hObject, eventdata, handles)
% hObject    handle to speckle (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if(handles.fileLoaded1 == 1)
    param = saltPepDensity();
    handles.outIm = imnoise(handles.inIm, 'speckle', param);
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function equalize_Callback(hObject, eventdata, handles)
% hObject    handle to equalize (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if(handles.fileLoaded1 == 1)
    
    handles.outIm = histeq(rgb2gray(handles.inIm)) %one more param can fit in;
    
    handles.outIm(:,:,2) = handles.outIm(:,:,1);
    handles.outIm(:,:,3) = handles.outIm(:,:,1);
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function median_Callback(hObject, eventdata, handles)
% hObject    handle to median (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.kSize = [15 15];
handles.padopt = 'zeros';

if (handles.fileLoaded1==1)
    
    [kSz padT] = chooseMedian();
    padT
    handles.kSize = [kSz kSz];
    handles.padopt = (padT);
    assignin('base', 'h', handles);
    %     gaussian, sobelX, prewitt, laplacian, sobelY, average, unsharp, disk, motion
    
    handles.outIm(:,:,1) = medfilt2(handles.inIm(:,:,1), handles.kSize, char(handles.padopt));
    handles.outIm(:,:,2) = medfilt2(handles.inIm(:,:,2), handles.kSize, char(handles.padopt));
    handles.outIm(:,:,3) = medfilt2(handles.inIm(:,:,3), handles.kSize, char(handles.padopt));
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function gaussian_Callback(hObject, eventdata, handles)
% hObject    handle to gaussian (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.kSize = [15 15];
handles.pad = 'replicate';

if (handles.fileLoaded1==1)
    
    param = gaussFilterParam();
    handles.kSize = [param(1) param(1)];
    handles.var = param(2);
    assignin('base', 'h', handles);
    H = fspecial('gaussian', handles.kSize,  (handles.var));
    handles.outIm = imfilter(handles.inIm, H, 'replicate');
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end

% --------------------------------------------------------------------
function laplacian_Callback(hObject, eventdata, handles)
% hObject    handle to laplacian (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.kSize = [15 15];
handles.pad = 'replicate';

if (handles.fileLoaded1==1)
    
    handles.alpha = lapFilterParam();
    
    assignin('base', 'h', handles);
    H = fspecial('laplacian', handles.alpha);
    handles.outIm = imfilter(handles.inIm, H, 'replicate');
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end

% --------------------------------------------------------------------
function sobelX_Callback(hObject, eventdata, handles)
% hObject    handle to sobelX (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.kSize = [15 15];
handles.pad = 'replicate';

if (handles.fileLoaded1==1)
    
    
    H = fspecial('sobel');
    handles.outIm = imfilter(handles.inIm, H, 'replicate');
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end

% --------------------------------------------------------------------
function sobelY_Callback(hObject, eventdata, handles)
% hObject    handle to sobelY (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.kSize = [15 15];
handles.pad = 'replicate';

if (handles.fileLoaded1==1)
    
    
    H = fspecial('sobel');
    handles.outIm = imfilter(handles.inIm, H', 'replicate');
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end

% --------------------------------------------------------------------
function log_Callback(hObject, eventdata, handles)
% hObject    handle to log (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.kSize = [15 15];
handles.pad = 'replicate';

if (handles.fileLoaded1==1)
    
    param = gaussFilterParam();
    handles.kSize = [param(1) param(1)];
    handles.var = param(2);
    assignin('base', 'h', handles);
    H = fspecial('log', handles.kSize,  (handles.var));
    handles.outIm = imfilter(handles.inIm, H, 'replicate');
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end




% --------------------------------------------------------------------
function kernelSet_Callback(hObject, eventdata, handles)
% hObject    handle to kernelSet (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



if (handles.fileLoaded1==1)
    handles.KernelSize = kernelSize();
    H = kernelParam(handles.KernelSize);
    if(sum(H(:)) ~= 0)
         H = H./sum(H(:));
    end
    H
    assignin('base', 'h', handles);
    
    handles.outIm(:,:,1) = filter2(H, handles.inIm(:,:,1));
    handles.outIm(:,:,2) = filter2(H, handles.inIm(:,:,2));
    handles.outIm(:,:,3) = filter2(H, handles.inIm(:,:,3));
    
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end




% --------------------------------------------------------------------
function cannyEdge_Callback(hObject, eventdata, handles)
% hObject    handle to cannyEdge (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if (handles.fileLoaded1==1)
    param = cannyParam();
    handles.outIm = canny(handles.inIm, param(1), param(2), 0.1);
    
    axes(handles.axes2); imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end



% --------------------------------------------------------------------
function houghCirc_Callback(hObject, eventdata, handles)
% hObject    handle to houghCirc (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    param = houghCircParam();
    [centers, radii, metric] = imfindcircles(handles.inIm, param);
    %  centersStrong5 = centers(1:5,:);
    % radiiStrong5 = radii(1:5);
    % metricStrong5 = metric(1:5);
    handles.outIm = handles.inIm;
    
    axes(handles.axes2);
    
    imshow(handles.outIm);
    viscircles(centers, radii,'EdgeColor', 'b');
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function houghLines_Callback(hObject, eventdata, handles)
% hObject    handle to houghLines (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    if size(handles.inIm,3) == 3
        rotI = rgb2gray(handles.inIm);
    end
    
    
    BW = edge(rotI,'canny');
    [H,T,R] = hough(BW);
    
    
    axes(handles.axes2);
    handles.outIm = rotI;
    imshow(handles.outIm); hold on;
    P  = houghpeaks(H,10,'threshold',ceil(0.3*max(H(:))));
    x = T(P(:,2)); y = R(P(:,1));
    plot(x,y,'s','color','white');
    % Find lines and plot them
    lines = houghlines(BW,T,R,P,'FillGap',5,'MinLength',7);
    
    max_len = 0;
    for k = 1:length(lines)
        xy = [lines(k).point1; lines(k).point2];
        plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');
        
        % Plot beginnings and ends of lines
        plot(xy(1,1),xy(1,2),'x','LineWidth',2,'Color','yellow');
        plot(xy(2,1),xy(2,2),'x','LineWidth',2,'Color','red');
        
        % Determine the endpoints of the longest line segment
        len = norm(lines(k).point1 - lines(k).point2);
        if ( len > max_len)
            max_len = len;
            xy_long = xy;
        end
    end
    
    % highlight the longest line segment
    plot(xy_long(:,1),xy_long(:,2),'LineWidth',2,'Color','blue');
    hold off;
    handles.fileLoaded2 = 1;
    
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function surf_Callback(hObject, eventdata, handles)
% hObject    handle to surf (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
    points = detectSURFFeatures(rgb2gray(handles.inIm));
    handles.outIm = handles.inIm;
    
    axes(handles.axes2);
    
    imshow(handles.outIm);hold on;
    plot(points.selectStrongest(10));
    hold off;
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function fast_Callback(hObject, eventdata, handles)
% hObject    handle to fast (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
    points = detectSURFFeatures(rgb2gray(handles.inIm));
    handles.outIm = handles.inIm;
    
    axes(handles.axes2);
    
    imshow(handles.outIm);hold on;
    plot(points.selectStrongest(50));
    hold off;
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function harrisC_Callback(hObject, eventdata, handles)
% hObject    handle to harrisC (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
    points = detectHarrisFeatures(rgb2gray(handles.inIm));
    handles.outIm = handles.inIm;
    
    axes(handles.axes2);
    
    imshow(handles.outIm);hold on;
    plot(points.selectStrongest(50));
    hold off;
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end




% --------------------------------------------------------------------
function calib_Callback(hObject, eventdata, handles)
% hObject    handle to calib (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
addpath('calib');
calib;




% --------------------------------------------------------------------
function sharpen_Callback(hObject, eventdata, handles)
% hObject    handle to sharpen (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
    param = sharpenParams(); %returns radius, amount and threhold
    
    
    handles.outIm = sharpen(handles.inIm, param(1), param(2), param(3));
    
    axes(handles.axes2);
    
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function choice_Callback(hObject, eventdata, handles)
% hObject    handle to choice (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
    [param1 param2 method se] = customMorph()
    
    
    handles.outIm = ApplyMorph(handles.inIm, method, se, param1, param2);%, param(1), param(2));
    
    axes(handles.axes2);
    
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function funda_Callback(hObject, eventdata, handles)
% hObject    handle to funda (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
    %%get the second image first
    [fileName, pathName, filterindex] = uigetfile({'*.*'},'Load Image File');
    if (fileName==0) % cancel pressed
        return;
    end
    handles.fullPath2 = [pathName fileName];
    [a, b, ext] = fileparts(fileName);
    availableExt = {'.bmp','.jpg','.jpeg','.tiff','.png','.gif'};
    FOUND = 0;
    for i=1:length(availableExt)
        if (strcmpi(ext, availableExt{i}))
            FOUND=1;
            break;
        end
    end
    if (FOUND==0)
        h = msgbox('File type not supported!','Error','error');
        return;
    end
    image2 = imread(handles.fullPath2);
    handles.outIm = image2;
    axes(handles.axes2);
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);

    [handles.flMeds handles.inliers matchedImage1 matchedImage2] = computeFundamentalMatrix(handles.inIm, handles.outIm);
    handles.flMeds
    handles.inliers
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% ask for display of epipolar lines
    choice = questdlg('Would you like to see Epipolar lines?', ...
        'Yes', ...
        'NO');
    % Handle response
    switch choice
        case 'Yes'
            calculateEpilines = 1;
        case 'Cake'
            calculateEpilines = 0;
    end
    
    if calculateEpilines == 1
        epiLines1 = epipolarLine(handles.flMeds', matchedImage2(handles.inliers, :).Location);

points1 = lineToBorderPoints(epiLines1, size(handles.inIm));
axes(handles.axes1);
imshow(handles.inIm);
hold on;

line(points1(:, [1,3])', points1(:, [2,4])');

[isIn, epipole] = isEpipoleInImage(handles.flMeds, size(handles.inIm));


epiLines2 = epipolarLine(handles.flMeds, matchedImage1(handles.inliers, :).Location);

points2 = lineToBorderPoints(epiLines2, size(handles.outIm));

axes(handles.axes2);
imshow(handles.outIm);
hold on;

line(points2(:, [1,3])', points2(:, [2,4])');

[isIn,epipole] = isEpipoleInImage(handles.flMeds, size(handles.outIm))

    end
        guidata(hObject, handles);
end


% --------------------------------------------------------------------
function homograph_Callback(hObject, eventdata, handles)
% hObject    handle to homograph (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    [fileName, pathName, filterindex] = uigetfile({'*.*'},'Load Image File');
        if (fileName==0) % cancel pressed
        return;
    end
    handles.fullPath2 = [pathName fileName];
    [a, b, ext] = fileparts(fileName);
    availableExt = {'.bmp','.jpg','.jpeg','.tiff','.png','.gif'};
    FOUND = 0;
    for i=1:length(availableExt)
        if (strcmpi(ext, availableExt{i}))
            FOUND=1;
            break;
        end
    end
    if (FOUND==0)
        h = msgbox('File type not supported!','Error','error');
        return;
    end
    image2 = imread(handles.fullPath2);
    handles.outIm = image2;
    axes(handles.axes2);
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    
    handles.outIm = ShowHomography(handles.inIm, handles.outIm);%, param(1), param(2));
    
    axes(handles.axes2);
    
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function contours_Callback(hObject, eventdata, handles)
% hObject    handle to contours (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function showContours_Callback(hObject, eventdata, handles)
% hObject    handle to showContours (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
  contourLvl = contourParam();
    handles.outIm = handles.inIm;
    
    if size(handles.outIm, 3) > 1
    handles.outIm = rgb2gray(handles.outIm);
    end
   
  h =  waitbar(.5, 'getting contours...');
    axes(handles.axes2);
        
    imshow(handles.outIm);

    imcontour(handles.outIm, contourLvl);
 
    waitbar(1,h, 'Done..');
    close(h);
    handles.fileLoaded2 = 1;
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function shapes_Callback(hObject, eventdata, handles)
% hObject    handle to shapes (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
    showAsCircle = 0;
handles.outIm = im2bw(handles.inIm);

handles.outIm = imfill(handles.outIm, 'holes');

handles.outIm = bwlabel(handles.outIm);

hold on;

rp = regionprops(handles.outIm, 'BoundingBox');

boundingBoxCount = length(rp);

for ii = 1 : boundingBoxCount
    
    if showAsCircle
        rectangle('Position', rp(ii).BoundingBox, 'Linewidth', 3, 'EdgeColor', 'r', 'Curvature', [1 1]);
    else
        rectangle('Position', rp(ii).BoundingBox, 'Linewidth', 3, 'EdgeColor', 'r');
    end
    
end
 axes(handles.axes2);
    
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function makelogo_Callback(hObject, eventdata, handles)
% hObject    handle to makelogo (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
     [fileName, pathName, filterindex] = uigetfile({'*.*'},'Load Image File');
        if (fileName==0) % cancel pressed
        return;
    end
    handles.fullPath2 = [pathName fileName];
    [a, b, ext] = fileparts(fileName);
    availableExt = {'.bmp','.jpg','.jpeg','.tiff','.png','.gif'};
    FOUND = 0;
    for i=1:length(availableExt)
        if (strcmpi(ext, availableExt{i}))
            FOUND=1;
            break;
        end
    end
    if (FOUND==0)
        h = msgbox('File type not supported!','Error','error');
        return;
    end
    image2 = imread(handles.fullPath2);
    handles.outIm = image2;
    axes(handles.axes2);
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
   
    %%begin rectangular ROI
    axes(handles.axes1);
    h = imrect;
    position = wait(h)
    delete(h);
    logoWt = logoWeight();
    handles.outIm = addLogo( handles.inIm, handles.outIm, floor(position(2)), floor(position(1)), logoWt, [floor(position(4)) floor(position(3))] );
    
    axes(handles.axes2);
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function maskROI_Callback(hObject, eventdata, handles)
% hObject    handle to maskROI (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
    h = impoly(handles.axes1);
    position = wait(h)
    [r c] = size(handles.inIm);
    clear handles.outIm;
    mask = poly2mask(position(:,1)', position(:,2)', c, r);
    handles.outIm = mask;
    
    axes(handles.axes2);
    
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
   
    guidata(hObject, handles);
end



% --------------------------------------------------------------------
function showMatches_Callback(hObject, eventdata, handles)
% hObject    handle to showMatches (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    [fileName, pathName, filterindex] = uigetfile({'*.*'},'Load Image File');
        if (fileName==0) % cancel pressed
        return;
    end
    handles.fullPath2 = [pathName fileName];
    [a, b, ext] = fileparts(fileName);
    availableExt = {'.bmp','.jpg','.jpeg','.tiff','.png','.gif'};
    FOUND = 0;
    for i=1:length(availableExt)
        if (strcmpi(ext, availableExt{i}))
            FOUND=1;
            break;
        end
    end
    if (FOUND==0)
        h = msgbox('File type not supported!','Error','error');
        return;
    end
    
    image2 = imread(handles.fullPath2);
    handles.outIm = image2;
    axes(handles.axes2);
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
    id = chooseFeatureMethod();
    showMatches(handles.inIm, handles.outIm, id);
   
end


% --------------------------------------------------------------------
function hsv_Callback(hObject, eventdata, handles)
% hObject    handle to hsv (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
   
    handles.outIm = rgb2hsv(handles.inIm);
    
    axes(handles.axes2);
    
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
   handles = makeHistograms(handles);
    guidata(hObject, handles);
end

% --------------------------------------------------------------------
function YCbCr_Callback(hObject, eventdata, handles)
% hObject    handle to YCbCr (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
   
    handles.outIm = rgb2ycbcr(handles.inIm);
    
    axes(handles.axes2);
    
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
   handles = makeHistograms(handles);
    guidata(hObject, handles);
end



% --------------------------------------------------------------------
function xyz_Callback(hObject, eventdata, handles)
% hObject    handle to xyz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
   
    handles.outIm = rgb2ntsc(handles.inIm);
    
    axes(handles.axes2);
    
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
   handles = makeHistograms(handles);
    guidata(hObject, handles);
end


% --------------------------------------------------------------------
function localThresh_Callback(hObject, eventdata, handles)
% hObject    handle to localThresh (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if (handles.fileLoaded1==1)
    
   param = localThreshParam();
    handles.outIm = localThresh(handles.inIm, param(1), param(2));
    
    axes(handles.axes2);
    
    imshow(handles.outIm);
    handles.fileLoaded2 = 1;
  
    guidata(hObject, handles);
end
