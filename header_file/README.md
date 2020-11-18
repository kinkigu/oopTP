# Add Header Files Here

## MemoList
* ***private 변수***  
    * **std::vector<std::string> wholePath** : 파일당 전체 경로  
    * **std::vector<std::string> fileList**  :파일들의 경로, wholePath와 순서가 동일
    * **std::map<int, std::string> pathType** : 최종 파일까지의 폴더 경로

* ***public 변수***
    * **std::string defaultFileName** : 저장할 파일 이름을 지정하지 않았을 경우의 파일명
    * **std::string defaultPath** : 파일들을 저장할 경로 (자동 경로 갱신 및 영구 경로 변환 기능 필요)
    
* ***public함수***
    * **MemoList()** : 생성자 - defaultPath를 탐색해 private 변수에 값들을 저장
    * **~MeomoList()** : 소멸자 - 소멸할 변수 존재x
    * **bool OpenList()** : 지정된 또는 Default Path에 저장된 파일들을 모두 보여줌
    * **bool MakeFile(std::string::filename)** : filename으로 특정한 값을 받지 않으면 defaultFileName으로 저장되는 값을 제목으로 하는 파일들의 매개해주는 파일을 생성
    * **bool ChangeDefaultFileName(std::string input_default)** : data를 저장하는 경로에 default_file_name.txt이라는 파일을 읽어와 파일 이름을 읽어내어 그 안에 저장된 값을 변경한다. (파일을 저장할 때, default로 이름을 정해주는 함수는 default값을 읽어와 그 값을 토대로 정하는 방식은 어떨까....)
    
* ***public Template***
    * **ChangeDefaultRoute()** : 굳이 템플릿을 안 써도 되지만, 교수님이 배운 내용 쓰면 점수 더 주실까봐 쓰는 함수; data를 저장하는 경로에 default_path.txt라는 파일이 있는데, 이를 읽어내어 그 안에 저장된 값을 변경한다. path에서 탐색이 불가능하다면, false 반환.

2020.11.18 23:51 김진휘
