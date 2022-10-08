def checkIfDuplicates_1(listOfElements):
    ''' Check if given list contains any duplicates '''
    if len(listOfElements) == len(set(listOfElements)):
        return False
    else:
        return True


def checkIfDuplicates_2(listOfElements):
    ''' Check if given list contains any duplicates '''
    setOfElements = set()
    for elem in listOfElements:
        if elem in setOfElements:
            return True
        else:
            setOfElements.add(elem)
    return False


def checkIfDuplicates_3(listOfElements):
    ''' Check if given list contains any duplicates '''
    for elem in listOfElements:
        if listOfElements.count(elem) > 1:
            return True
    return False


def main():

    listOfElements = ['Hello', 'Ok', 'is', 'Ok',
                      'test', 'this', 'is', 'a', 'test']
    print('*** Check for duplicates in list using Set and comparing sizes ***')
    result = checkIfDuplicates_1(listOfElements)
    if result:
        print('Yes, list contains duplicates')
    else:
        print('No duplicates found in list')

    print('*** Check for duplicates in list using Set and looking for first duplicate ***')

    result = checkIfDuplicates_2(listOfElements)

    if result:
        print('Yes, list contains duplicates')
    else:
        print('No duplicates found in list')

    print('*** Check if list contains duplicates using list.count() ***')
    result = checkIfDuplicates_3(listOfElements)

    if result:
        print('Yes, list contains duplicates')
    else:
        print('No duplicates found in list')


if __name__ == '__main__':
    main()
