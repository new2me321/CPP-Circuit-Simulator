#ifndef CIRCUIT_SIMULATOR_INVERSE_H_
#define CIRCUIT_SIMULATOR_INVERSE_H_

#include <iomanip> // std::fixed && std::setprecision 

#include <boost/numeric/odeint.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>

typedef boost::numeric::ublas::matrix<double> matrix;
typedef boost::numeric::ublas::matrix<std::complex<double>> cmatrix;

inline bool inverse (const cmatrix& input, cmatrix& result) { 
	using permMatrix = boost::numeric::ublas::permutation_matrix<double>;
	using identityMatrix = boost::numeric::ublas::identity_matrix<double>;

	// create copy of input
	cmatrix copyInput(input); 

	// permutation matrix
	permMatrix pm(copyInput.size1()); 

	// lu factorization
	int singular = lu_factorize(copyInput, pm); 
	if(singular != 0)
		return false; 

	// set result value as identity
	result.assign(identityMatrix(copyInput.size1())); 

	// lu substitute to result
	lu_substitute(copyInput, pm, result); 
	return true; 
}

inline bool operator==(const matrix& m, const matrix& n){
  auto equalFloat = [](double a, double b){
		return std::fabs(a - b) < 1e-5;
  };

  bool result = (m.size1() == n.size1()) && (m.size2() == n.size2());

  if(result){
		for(unsigned i = 0; result && i < m.size1(); i++){
			for(unsigned j = 0; result && j < m.size2(); j++){
				result &= equalFloat(m(i,j), n(i,j));
			}
		}
  }
	
  return result;
}

inline std::ostream& operator<<(std::ostream& os, const matrix& m){
	os << "Matrix(" << m.size1() << ", " << m.size2() << "):\n" << std::fixed << std::setprecision(3);

	for(boost::numeric::ublas::matrix<double>::size_type row = 0; row < m.size1(); row++){
		for(boost::numeric::ublas::matrix<double>::size_type col = 0; col < m.size2(); col++){
			os << m(row, col) << "\t";
		}
		os << "\n";
	}

	return os;
}

#endif