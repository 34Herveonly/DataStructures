/*  “Fruit Into Two Baskets – Variant”
 (With One Unlimited Basket + One Limited to 2 Fruits) */

 from collections import defaultdict

def max_fruits_with_basket_rule(fruits):
    count = defaultdict(int)
    start = 0
    max_len = 0
    limited_type = -1
    types = 0

    for end in range(len(fruits)):
        fruit = fruits[end]

        if count[fruit] == 0:
            types += 1
        count[fruit] += 1

        # Assign basket B if not set
        if limited_type == -1 or (fruit != limited_type and count[fruit] <= 2):
            limited_type = fruit

        # If basket B exceeds its 2-fruit limit or 3rd type appears
        while types > 2 or (fruit == limited_type and count[fruit] > 2):
            left_fruit = fruits[start]
            count[left_fruit] -= 1
            if count[left_fruit] == 0:
                types -= 1
                if left_fruit == limited_type:
                    limited_type = -1
                    for f in count:
                        if count[f] > 0 and count[f] <= 2:
                            limited_type = f
                            break
            start += 1

        max_len = max(max_len, end - start + 1)

    return max_len

# Test input
fruits = [1, 2, 2, 1, 3, 1, 1, 2]
print(max_fruits_with_basket_rule(fruits))  # Should print the correct max length

/*

For this case it kinda works like the logic from longest sub-array where we will need to use a sliding window to be able to traverse through our given stall of fruits or array of integers and then as we traverse from left to right of our array we will use a hashmap to keep track of types of fruits counted so that they wont exceed our conditions and whenever we find one of the fruits in our array to be making our logic be false we will stop right there and remove one type from the left and as we do so we must makesure also that in the second basket there is only 2fruits of same type as we were told in instructions    

*/