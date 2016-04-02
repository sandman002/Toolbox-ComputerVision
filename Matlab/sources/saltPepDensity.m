function density = saltPepDensity()

    d = dialog('Position',[300 300 250 180],'Name','Density/Factor');
    txt = uicontrol('Parent',d,...
           'Style','text',...
           'Position',[20 100 210 40],...
           'String','Density/Factor');
    kSize =  uicontrol('Parent', d, 'Style','edit',...
             'Position', [75 90 100 25],'String','3', 'Callback', @setValue)


          
    btn = uicontrol('Parent',d,...
           'Position',[89 20 70 25],...
           'String','Close',...
           'Callback','delete(gcf)');
   density = 0.5;
    % Wait for d to close before running to completion
    uiwait(d);
    
    function [] = setValue(kSize, callbackdata)
      density = str2num(get(kSize, 'string'));
    end
        

end