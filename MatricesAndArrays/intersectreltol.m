function [ IA, IB ] = intersectreltol( A, B, reltol )
%INTERSECTRELTOL Returns the indices IA such that A(IA) and B(IB) produce
%identical elements C, up to a relative tolerance RELTOL. C is defined as 
% A(IA), and is returned as a column vector.
%
% A, B will be treated as 1-dimensional arrays, regardless of their actual 
% size; calling INTERSECTRELTOL(A,B,RELTOL) is identical to calling
% INTERSECTRELTOL(A(:),B(:),RELTOL) in all cases.

absdiff = abs(bsxfun(@minus,A(:),B(:).'));

IA = find( any( bsxfun(@le, absdiff, reltol * abs(A(:))), 2 ) );
IB = find( any( bsxfun(@le, absdiff, reltol * abs(B(:).')), 1 ) ).';


end

% %Modified from stackoverflow:
% IA = reshape(find(any(squeeze(all(bsxfun(@le,abs(bsxfun(@minus,B(:),permute(A(:),[3 2 1]))),reltol*abs(B(:))),2)),1)),[],1);