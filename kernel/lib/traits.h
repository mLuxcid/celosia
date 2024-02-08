#ifndef KERNEL_LIB_TRAITS_H_
#define KERNEL_LIB_TRAITS_H_

// Same
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

// IsPtr
template <typename T>
struct _IsPtr {
    static constexpr bool value = false;
};

template <typename T>
struct _IsPtr<const T> {
    static constexpr bool value = false;
};

template <typename T>
struct _IsPtr<T *> {
    static constexpr bool value = true;
};

template <typename T>
struct _IsPtr<T const *> {
    static constexpr bool value = true;
};

template <typename T>
struct _IsPtr<T *volatile> {
    static constexpr bool value = true;
};

template <typename T>
struct _IsPtr<T const *volatile> {
    static constexpr bool value = true;
};

template <typename T>
concept IsPtr = _IsPtr<T>::value;

#endif /* KERNEL_LIB_TRAITS_H_ */
