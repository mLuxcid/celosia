#ifndef KERNEL_LIB_TRAITS_H_
#define KERNEL_LIB_TRAITS_H_

template <typename T, typename U>
struct _Same {
    static constexpr bool value = false;
};

template <typename T>
struct _Same<T, T> {
    static constexpr bool value = true;
};

template <typename T, typename U>
concept Same = _Same<T, U>::value;

#endif /* KERNEL_LIB_TRAITS_H_ */
