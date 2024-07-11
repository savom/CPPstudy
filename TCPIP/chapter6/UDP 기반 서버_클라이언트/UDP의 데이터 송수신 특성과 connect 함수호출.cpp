데이터의 경계가 존재하는 UDP 소켓

	UDP는 데이터의 경계가 존재하는 프로토콜이므로, 데이터 송수신 과정에서 호출하는 입출력함수의 호출횟수가 큰 의미를 가진다.
	때문에 입력함수의 호출횟수와 출력함수의 호출횟수가 완벽히 일치해야 송신된 데이터를 전부 수신할 수 있다.

		if (bind(sock, (struct sockaddr*)&my_adr, sizeof(my_adr)) == -1)
			error_handling("bind() error");

		for (i = 0; i < 3; i++)
		{
			sleep(5);	// delay 5 sec.
			adr_sz = sizeof(your_adr);
			str_len = recvfrom(sock, message, BUF_SIZE, 0,
				(struct sockaddr*)&your_adr, &adr_sz);

			printf("Message %d: %s \n", i + 1, message);
		}

		데이터의 경계가 존재하기 때문에 5초간의 delay를 삽입해도 총 3개의 메시지를 3번의 recvfrom 함수호출을 통해서 수신한다.

		sendto(sock, msg1, sizeof(msg1), 0,
			(struct sockaddr*)&your_adr, sizeof(your_adr));
		sendto(sock, msg2, sizeof(msg2), 0,
			(struct sockaddr*)&your_adr, sizeof(your_adr));
		sendto(sock, msg3, sizeof(msg3), 0,
			(struct sockaddr*)&your_adr, sizeof(your_adr));

			데이터의 전송에 있어서 TCP와의 유일한 차이점은 사용하는 함수가 다르고 전달한 목적지 정보를 매 호출 시마다 지정한다는 점이다.


connected UDP 소켓, unconnected UDP 소켓

	sendto 함수호출을 통한 데이터의 전송과정은 크게 세 단계다.
		- UDP 소켓에 목적지의 IP와 PORT번호 등록
		- 데이터 전송
		- UDP 소켓에 등록된 목적지 정보 삭제

	connected UDP 소켓의 경우는 1단계와 3단계의 과정을 매회 거치지 않는다.

connected UDP 소켓 생성

	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (sock == -1)
		error_handling("socket() error");

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));

	connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));

		connected UDP 소켓은 TCP와 같이 상대 소켓과의 연결을 의미하지 않는다.
		그러나 소켓에 목적지에 대한 정보는 등록이 된다.
		그리고 connected UDP 소켓을 대상으로는 read, write 함수호출이 가능하다.

