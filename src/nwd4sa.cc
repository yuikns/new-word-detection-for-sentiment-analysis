#include <cstdio>

#include "argcv/ir/index/analyzer/lexicon.hh"
#include "argcv/ir/index/analyzer/basic_tokenlizer.hh"
#include "argcv/ir/index/analyzer/basic_cn_analyzer.hh"

using namespace argcv::ir::index::analyzer;

void lexicon_sample() {
    lexicon lex("data.ldb");
    size_t sz = lex.load("../data/lexicon/webdict_with_freq.txt");
    printf("dict loaded, with size: %zu \n", sz);
    char buff[1024];
    while (scanf("%s", buff) > 0) {
        printf("%s : count : %zu , level : %zu \n", buff, lex.count(buff), lex.level(buff));
    }
}

int main(int argc, char* argv[]) {
    lexicon lex("data.ldb");
    if (argc > 1 && strcmp(argv[1], "load") == 0) {
        if (argc > 2) {
            printf("loading lexicon from %s ... ", argv[2]);
            fflush(NULL);
            size_t lsz = lex.load(argv[2]);
            printf(" done, size: [%zu]\n", lsz);
        } else {
            const char* lex_path = "../data/lexicon/webdict_with_freq.txt";
            printf("loading lexicon from %s ... ", lex_path);
            fflush(NULL);
            size_t lsz = lex.load(lex_path);
            printf(" done, size: [%zu]\n", lsz);
        }
    }
    basic_tokenlizer tokens(
        "【废土科学指南：F代表辐射，A代表原子】战争，战争永不改变。今天是《辐射4》上市的日子，虽然距离1代已经"
        "过去了十八年，"
        "但和战争一样不变的，只有废土，那个承载了五十年代原子未来想象的废土。现实的物理学虽然和游戏中不同，"
        "但我们都有同样的梦想和同样的恐惧 ... some english words "
        "北京城连续几天阴天，然而在低空云层之上别有一番天地。云海遮住了城市灯光，冬季夜空格外耀眼。"
        "\n"
        "结婚的和尚未结婚的同志们"
        "\n"
        "只听得一个女子低低应了一声。绿竹翁道：“姑姑请看，这部琴谱可有些古怪。”那女子又嗯了一声，琴音响起，调"
        "了调弦，停了一会，似是在将断了的琴弦换去，又调了调弦，便奏了起来。初时所奏和绿竹翁相同，到后来越转越"
        "高，那琴韵竟然履险如夷，举重若轻，毫不费力的便转了上去。令狐冲又惊又喜，依稀记得便是那天晚上所听到曲"
        "洋所奏的琴韵。这一曲时而慷慨激昂，时而温柔雅致，令狐冲虽不明乐理，但觉这位婆婆所奏，和曲洋所奏的曲调"
        "虽同，意趣却大有差别。这婆婆所奏的曲调平和中正，令人听着只觉音乐之美，却无曲洋所奏热血如沸的激奋。奏"
        "了良久，琴韵渐缓，似乎乐音在不住远去，倒像奏琴之人走出了数十丈之遥，又走到数里之外，细微几不可再闻"
        "。"
        "\n"
        "工信处女干事每月经过下属科室都要亲口交代24口交换机等技术性器件的安装工作"
        "\n"
        "小明硕士毕业于中国科学院计算所"
        "\n"
        "检察院鲍绍坤检察长");
    basic_cn_analyzer bcanz(&tokens, &lex);
    bcanz.reset();
    std::string term;
    while (bcanz.next(term)) {
        printf("%s ", term.c_str());
    }
    printf("\n");
    return 0;
}