function ATAP_make_all

[chapnames,pdfnames]	=	deal(repmat({'chap'},28+1,1));
for n = 1:28
    chapnames{n}	=	[chapnames{n},num2str(n),'.m'];
    pdfnames{n}     =	[pdfnames{n},num2str(n),'.pdf'];
end
chapnames{28+1}	=   'refs.m';
pdfnames{28+1}	=   'refs.pdf';

%% Make all pdfs
% args	=   { 'format','pdf','outputDir',cd,'imageFormat','bmp' };
% for ii = 1:28+1
%     tic
%     try
%         eval_publish(chapnames{ii},args{:});
%     catch me
%         warning(me.message);
%     end
%     close all force
%     display_toc_time(toc,[chapnames{ii} ' to pdf']);
% end

%% Make all tex files
args	=   { 'format','latex','imageFormat','png' };
for ii = 1:28+1
    tic
    try
        eval_publish(chapnames{ii},args{:});
    catch me
        warning(me.message);
    end
    close all force
    display_toc_time(toc,[chapnames{ii} ' to tex']);
end

%% concatenate pdfs
tic
append_pdfs('ATAP.pdf',pdfnames{:});
display_toc_time(toc,'append_pdfs');

end

function eval_publish(varargin)
% call publish in subfunction so that local variables are unaffected
publish(varargin{:});
end