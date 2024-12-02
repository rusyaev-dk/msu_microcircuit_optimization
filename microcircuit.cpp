#include "microcircuit.hpp"

#include "math.h"

Microcircuit::Microcircuit(std::ostream& stream)
    : _logger(InstructionLogger(stream)) {
    _stack = Stack<long long>();

    _total_cycles = 0;
}

long long Microcircuit::compute_power(long long x, long long n) {
    if (x == 0 || n == 1) return x;
    if (x == 1 || n == 0) return 1ll;

    _logger.log("x =", x);
    _logger.log("n =", n);
    _logger.log(MCInstruction::Write, x);
    _write(x);

    _binary_exponentiation(x, n);
    // _brute_force(x, n);

    _logger.log("Answer:", _stack.peek());
    _logger.log("Total cycles:", _total_cycles);
    _logger.log("\n");
    _total_cycles = 0;
    return _stack.peek();
}

void Microcircuit::_brute_force(long long x, long long n) {
    _write(_stack.peek());
    for (long long i = 1; i < n; i++) {
        _logger.log(MCInstruction::Mul);
        _mul();
    }
}

void Microcircuit::_binary_exponentiation(long long x, long long n) {
    std::vector<long long> bin;
    while (n > 0) {
        bin.push_back(n % 2);
        n /= 2;
    }

    for (long long i = bin.size() - 2; i >= 0; i--) {
        // начинаем с предпоследнего бита
        _logger.log(MCInstruction::Pow, 2);
        _pow_n(2);
        if (bin[i] == 1) {
            _logger.log(MCInstruction::Write, x);
            _write(x);

            _logger.log(MCInstruction::Mul);
            _mul();
        }
    }

    // 5 = 1 0 1
    // long long int result = 1;  // Начальный результат (2^0)

    // while (n > 0) {
    //     // Если текущий бит равен 1, умножаем на x
    //     if (n & 1) {  // Проверяем последний бит (n & 1 дает 1, если
    //     последний бит равен 1)
    //         _logger.log(MCInstruction::Write, result);
    //         _write(result);
    //         _logger.log(MCInstruction::Mul);
    //         _mul();  // Умножаем результат на x
    //     }

    //     // Возводим в квадрат текущий результат
    //     if (n == 1) {  // Завершаем цикл, если n стало равно 1 (последний бит
    //     был обработан)
    //         break;
    //     }

    //     _logger.log(MCInstruction::Pow, 2);
    //     _pow_n(2);  // Возводим в квадрат (возводим в степень 2)

    //     // Сдвигаем число n на 1 вправо
    //     n >>= 1;
    // }
    // _write(x);
    // _mul();
}

void Microcircuit::_write(long long x) {
    _stack.push(x);

    _total_cycles++;
};

void Microcircuit::_mul() {
    long long top = _stack.peek();
    long long preTop = _stack.penultimate();
    _stack.rewrite_top(top * preTop);

    _total_cycles++;
}

void Microcircuit::_pow_n(long long n) {
    if (_stack.is_empty()) return;

    long long base = _stack.peek();
    _stack.pop();
    _write(base);

    for (long long i = 1; i < n; i++) {
        _write(base);
        _mul();
    }
}

void Microcircuit::clear() {
    _stack.clear();
    _total_cycles = 0;
}
