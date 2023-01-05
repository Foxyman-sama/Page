#include "test/Test.h"

#ifdef RECEIVE_TEST
#include "receivertest.hpp"
#endif
#ifdef FORMATER_TEST
#include "formatertest.hpp"
#endif
#ifdef EXTRACTOR_TEST
#include "extractortest.hpp"
#endif
#ifdef CACHER_TEST
#include "cachertest.hpp"
#endif
#ifdef FILTERER_TEST
#include "filterertest.hpp"
#endif

int main() {
#ifdef RECEIVE_TEST
    receiverTest<HTMLReceiver>();
#endif
#ifdef FORMATER_TEST
    formaterTest<HTMLFormater>();
#endif
#ifdef EXTRACTOR_TEST
    extractorTest<HTMLExtractor>();
#endif
#ifdef CACHER_TEST
    cacherTest<XMLCacher>();
#endif
#ifdef FILTERER_TEST
    filtererTest<XMLFilterer>();
    filtererTest<VectorFilterer>();
#endif
    system("pause");
}