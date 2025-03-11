close('all'), clear, clc;

%semnal sinusoidal
t = linspace(0, 1, 1000); 
x = cos(2*pi*10*t); 
Fs=41000;


[x, Fs] = audioread("chitara2.wav");

% Amplificare [dB]
g_dB = 0;
g = 10^(g_dB / 20);

% Prag de compresie [dB]
tr_dB = 0;
tr = 10^(tr_dB / 20);

% Nivel de clipping [%]
clip_p = 20;
clip = 1 + (clip_p/100)*(10-1);


% 0% -> 1
% 100%  -> 11
%clip_p = (clip-1)/(10-1)*100;

% Implementare Overdrive
y = zeros(length(x), 1);

for i = 1:length(y)
    if abs(x(i)) <= tr
        y(i) = g * x(i);
    elseif (x(i) > 0)
        y(i) = g * (tr + (x(i) - tr) / clip);
    else
        y(i) = g * (-tr + (x(i) + tr) / clip);
    end
end

% Limitare semnal (pentru  gain mare)
y(y > 1) = 1;
y(y < -1) = -1;


t = 0:length(y)-1;

% Grafice
subplot(2, 1, 1);
hold off;
plot(t, x);
title('Semnal Initial');
xlabel('Timp [s]');
ylabel('Amplitudine');
ylim([-1 1]); 

subplot(2, 1, 2);
hold off;
plot(t, y);
title('Semnal cu Overdrive');
xlabel('Timp [s]');
ylabel('Amplitudine');
ylim([-1 1]); 

% Redare semnal 
sound(y, Fs);
pause(10); 
clear sound;
