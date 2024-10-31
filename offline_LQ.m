function [P,F] = offline_LQ(A,B,Q,R,S,M,N)
P(:,:,N+1) = S;

for i=N:-1:1
    F(i,:) = inv(R+B'*P(:,:,i+1)*B)*B'*P(:,:,i+1)*A;
    P(:,:,i) = Q+A'*P(:,:,i+1)*A-A'*P(:,:,i+1)*B*inv(R+B'*P(:,:,i+1)*B)...
        *B'*P(:,:,i+1)*A;
end
