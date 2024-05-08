import random

# Define responses for different user inputs
responses = {
    "greeting": ["Hello! Welcome to PizzaBot.", "Hi there! How can I help you today?"],
    "menu": ["Sure, here's our menu:\n- Margherita: $10\n- Pepperoni: $12\n- Veggie: $11"],
    "order": ["Great choice!", "Excellent!"],
    "thanks": ["You're welcome!", "My pleasure!", "Anytime!"],
    "goodbye": ["Goodbye! Have a great day!", "See you next time!"]
}

# Define function to generate a response based on user input
def generate_response(user_input):
    user_input = user_input.lower()
    if "hi" in user_input or "hello" in user_input:
        return random.choice(responses["greeting"])
    elif "menu" in user_input or "options" in user_input:
        return responses["menu"]
    elif any(word in user_input for word in ["order", "want", "get"]):
        return random.choice(responses["order"])
    elif "thanks" in user_input or "thank you" in user_input:
        return random.choice(responses["thanks"])
    elif "bye" in user_input or "goodbye" in user_input:
        return random.choice(responses["goodbye"])
    else:
        return "I'm sorry, I didn't understand that."

# Define main function for chatbot interaction
def chat():
    print("PizzaBot: " + generate_response("hi"))
    while True:
        user_input = input("You: ")
        if user_input.lower() == "exit":
            print("PizzaBot: " + generate_response("goodbye"))
            break
        else:
            print("PizzaBot: " + generate_response(user_input))

# Start the chatbot
chat()