import re

ad = [] #본인 주소
li = [] #외부 링크

sb = [] #기본 점수
nl = [] #외부 링크 수
sl = [] #링크 점수
sm = [] #매칭 점수

def solution(word, pages):
    
    word = word.lower()
    
    #파싱
    for page in pages:
        
        page = page.lower()

        url = re.search('<meta property=\"og:url\" content=\"https://([\S]+)\".*/>', page).group(1)
        links = re.findall('<a href=\"https://([\S]+)\">', page)
        
        cnt = 0
        for w in re.findall('[a-z]+', page):
            if w == word:
                cnt += 1
        
        ad.append(url)
        sb.append(cnt)
        sl.append(0)
        sm.append(0)
        
        if links is None:
            li.append([])
            nl.append(0)
        else: 
            li.append(links)
            nl.append(len(links))
            

    #링크점수 구하기
    for i in range(len(li)):
        if nl[i] == 0: continue
        val = sb[i]/nl[i] #기본점수/외부링크수
        for p in li[i]:
            if (p in ad):
                idx = ad.index(p)
                sl[idx] += val
    
    #매칭점수 구하기
    mx = -1
    mxidx = -1
    for i in range(len(sm)):
        sm[i] = sb[i] + sl[i]
        if sm[i] > mx:
            mx = sm[i]
            mxidx = i
            
    return mxidx