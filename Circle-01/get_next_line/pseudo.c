#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char	*buf;			// read함수로 버퍼사이즈만큼 읽어올 때 저장되는 스트림
	static char	*backup;	// 개행을 만나기 전까지의 문자열을 합치면서 저장할 포인터
	int		fd;				// 파일디스크립터 테이블의 인덱스 값
	int		read_size;		// read 함수로 읽어온 바이트의 양

	if ( fd 불가능 조건 || line이 들어오지 않았을 떄 || 버퍼사이즈 불가능 조건 ||
			버퍼 저장할 문자열 malloc 에러처리 )
		return (-1);
	while ( read_size = read(fd, 버퍼, 버퍼사이즈))
	{
		backup = 문자열 합치기 (backup , buf)
		if ( backup 에 개행이 있으면? )
			return (문자열 처리 및 return value 처리)
	}
	/* function return_check() 에서 고려할 내용
	read 로 읽어온 사이즈가 0으로 나왔을 경우 처리할 조건들
	1. read_size = -1
		오류가 발생했으므로 return -1
	2. read_size = 0, backup = NULL
		라인에 빈 문자열을 할당해주고 return 0
	3. read_size = 0, backup 이 남아있을 때
		backup에 저장한 문자열을 line에 넣고 return 0
	*/
	return ( return_check() )
}
