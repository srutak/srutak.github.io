file=load('highdata.txt');
x = file(:,1);
y1 = file(:,2);
y2 = file(:,3);
y3 = file(:,4);
hold on
figure(1)
plot(x,y1,'r:','linewidth',3)
xlabel('Number of processes')
ylabel('Time')

plot(x,y2,'b:','linewidth',3)
xlabel('Number of processes')
ylabel('Time')

plot(x,y3,'g:','linewidth',3)
xlabel('Number of processes')
ylabel('Time')
legend('Time(ring)','Time(star)', 'Time(collective)')