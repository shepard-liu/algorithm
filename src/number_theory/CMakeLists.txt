cxx_test(gcd_test "gcd_test.cxx;gcd.cxx")
cxx_test(bezout_coeffs_test "bezout_coeffs_test.cxx;bezout_coeffs.cxx")
cxx_test(modular_inverse_test "gcd.cxx;bezout_coeffs.cxx;modular_inverse_test.cxx;modular_inverse.cxx")
cxx_test(is_prime_test "is_prime_test.cxx;is_prime.cxx")
cxx_test(prime_factors_test "is_prime.cxx;prime_factors_test.cxx;prime_factors.cxx")
cxx_test(solve_linear_congruent_system_test "gcd.cxx;bezout_coeffs.cxx;is_prime.cxx;prime_factors.cxx;modular_inverse.cxx;solve_linear_congruent_system_test.cxx;solve_linear_congruent_system.cxx")
cxx_test(modular_exponentiation_test "modular_exponentiation_test.cxx;modular_exponentiation.cxx")
cxx_test(miller_test_test "miller_test_test.cxx;miller_test.cxx;modular_exponentiation.cxx")
cxx_test(discrete_logarithm_test "discrete_logarithm_test.cxx;discrete_logarithm.cxx;modular_exponentiation.cxx")
cxx_test(prng_test "prng_test.cxx;prng.cxx;modular_exponentiation.cxx")