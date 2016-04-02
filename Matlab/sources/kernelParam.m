function param = kernelParam(n)
param = zeros(n,n);
d = dialog('Position',[300 300 (80*n)+100 (30*n)+100],'Name','Gaussian Filter parameters');
% txt = uicontrol('Parent',d,...
%     'Style','text',...
%     'Position',[50 (30*n)+50 210 40],...
%     'String','Kernel Size');
for i=1:n
    for j=1:n
KSize(i,j) =  uicontrol('Parent', d, 'Style','edit',...
    'Position', [50+(i-1)*80 (30*n)+30-(j-1)*30 50 25],'String','0', 'CallBack', {@meanValue, i,j});
    end
end


btn = uicontrol('Parent',d,...
    'Position',[100 (30*n)+60 100 20],...
    'String','Apply',...
    'Callback','delete(gcf)');


% Wait for d to close before running to completion
uiwait(d);

    function [] = meanValue(kSize, callbackdata, x,y)
        param(x,y) = str2num(get(kSize, 'string'));
  
    end

end