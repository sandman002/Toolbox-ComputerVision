function param = logoWeight()

    d = dialog('Position',[300 300 250 180],'Name','Logo Weight');
    txt = uicontrol('Parent',d,...
           'Style','text',...
           'Position',[20 100 210 40],...
           'String','Weight');
    KSize =  uicontrol('Parent', d, 'Style','edit',...
             'Position', [75 90 100 25],'String','0.5', 'Callback', @meanValue)

    btn = uicontrol('Parent',d,...
           'Position',[89 20 70 25],...
           'String','Apply',...
           'Callback','delete(gcf)');
   param = 1;
   
    % Wait for d to close before running to completion
    uiwait(d);
    
    function [] = meanValue(kSize, callbackdata)
      param = str2num(get(kSize, 'string'));
    end

   
end