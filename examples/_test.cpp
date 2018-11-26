// Used for testing, do not use it as an example
#include <iostream>

#include "qpp.h"
#include "experimental/experimental.h"

int main() {
    using namespace qpp;
    idx d = 2;
    idx n = 3;
    idx D = std::pow(d, n);

    ket input = randket(D);
    ket result = QFT(input, d);
    std::cout << norm(gt.Fd(D) * input - result) << '\n';

    ket a = randket(D);
    ket b = randket(D);
    std::cout << norm(kron(a, b) - gt.SWAPd(D) * kron(b, a)) << '\n';

    ket psi = 0000_ket;
    ket phi = applyQFT(psi, {1, 2});
    std::cout << disp(phi) << '\n';
}
